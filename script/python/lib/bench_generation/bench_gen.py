#! /usr/bin/env python
# -*- coding: iso-8859-15  -*-
##############################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################


"""generation of a global include header for functor unit tests
"""
__author__    = "Lapreste Jean-thierry (lapreste@univ-bpclermont.fr)"
__version__   = "$Revision: 1.0 $"
__date__      = "$Date: 2010    $"
__copyright__ = """ Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
                    Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI"""
__license__   = "Boost Software License, Version 1.0"

import os
import sys
sys.path.insert(0,os.path.join(os.path.dirname(os.path.realpath(__file__)),'..',"nt2_generation"))
from unit_base_gen import Base_gen
sys.path.pop(0)
sys.path.insert(0,os.path.join(os.path.dirname(os.path.realpath(__file__)),'..',"nt2_adding"))
from headerfiles import Headers
sys.path.pop(0)

import re
import datetime

class Bench_gen() :
    def __init__(self, base_gen) :
        self.bg   = base_gen
        self.mode = self.bg.get_fct_mode()
        self.__gen_result = self.__create_unit_txt()

    def get_gen_result(self) : return  self.__gen_result

    def __create_unit_txt(self) :
        """ auxilliary of create_bench
        """
        name = self.bg.get_fct_name()
        tb_name = self.bg.get_tb_name()
        mode = self.bg.get_fct_mode()
        nsp = "" if self.bg.get_tb_style()=="sys" else tb_name+'::'
        txt = [
            '#define NT2_BENCH_MODULE "nt2 %s toolbox - %s/%s Mode"'%(tb_name,name,mode),
            "",
            "//////////////////////////////////////////////////////////////////////////////",
            "// timing Test behavior of %s components in %s mode"%(tb_name,mode),
            "//////////////////////////////////////////////////////////////////////////////",
            ""
            "#include <nt2/toolbox/%s/include/%s.hpp>"%(tb_name,name.lower()),
            "#include <nt2/sdk/unit/benchmark.hpp>",
            "#include <nt2/sdk/unit/bench_includes.hpp>",
            "#include <cmath>",
            "" if mode=='scalar' else "typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;",
            "",
            "//////////////////////////////////////////////////////////////////////////////",
            "// %s runtime benchmark for functor<%s_> from %s"%(mode,name,tb_name),
            "//////////////////////////////////////////////////////////////////////////////",
            "using nt2::%stag::%s_;"%(nsp,name.lower()),
            "",
            "//////////////////////////////////////////////////////////////////////////////",
            "// range macro",
            "//////////////////////////////////////////////////////////////////////////////",
            "#define RS(T,V1,V2) (T, %(T)s(V1) ,%(T)s(V2))"% {"T" :"" if mode=='simd' else "T"},
            "",
            ]
        txtf = [
            "",
            "#undef RS",
            "",
            ]
        dl = self.bg.get_fct_dict_list()
        for d in dl :
            d1 = d.get('bench',False)
            if d1 :
                pass
            else :
                d1 = { "arity"  : int(d["functor"]["arity"]), 
                       "ranges" : d["unit"]["ranges"],
                       "types"  : d["functor"]['types'],
                       "type_defs": d["functor"]['type_defs'],
                       "call_types" :d["functor"]["call_types"],
                       }
                if d1["call_types"] == [] : d1["call_types"] = ["T"]
##            PrettyPrinter().pprint(d1)

            if True :
                tpl = d["functor"].get("tpl","")
                call =  "  NT2_TIMING(%s_%s,%s)" % (name,tpl,"%s")
                variety = { 'real_'         : ["float","double"],
                            'signed_int_'   : ["int8_t","int16_t","int32_t","int64_t"],
                            'unsigned_int_' : ["uint8_t","uint16_t","uint32_t","uint64_t"],
                            'float'         : ["float"],
                            'double'        : ["double"],
                            'float_'        : ["float"],
                            'double_'       : ["double"],
                            'integer_'      : ["int8_t","int16_t","int32_t","int64_t","uint8_t","uint16_t","uint32_t","uint64_t"],
                            'int32_t'       : ["int32_t"],
                            'int64_t'       : ["int64_t"],
                            'uint32_t'      : ["uint32_t"],
                            'uint64_t'      : ["uint64_t"],
                            'int64_'        : ["uint64_t","int64_t"],
                            'int32_'        : ["uint32_t","int32_t"],
                            'int16_'        : ["uint16_t","int16_t"],
                            'int8_'         : ["uint8_t","int8_t"],
                             }
                r = []
                k=1
                for typ in d1["types"] :
                    for t in variety[typ] :
                        r += ["namespace n%s {"%str(k) ]
                        k+=1;
                        r.append("  typedef %s T;"%t )
                        r.append("  typedef nt2::meta::as_integer<T>::type iT;")
##                        r += ["  "+td for td in d1["type_defs"]]
                        if mode == "simd" :
                            r += ["  typedef nt2::simd::native<%s,ext_t> v%s;"%(ct,ct)  for ct in d1["call_types"] ]
                        tpl = "(RS(%s,%s,%s))"
                        rges = d1["ranges"].get(typ,d1["ranges"].get("default",None))
                        print("rges  %s"%rges)
                        if isinstance(rges[0][0],list) :
                            print(rges)
                        if not isinstance(rges[0][0],list) : rges = [rges]
                        prefix = "v" if mode == 'simd' else ''
                        calls = d1["call_types"]*d1["arity"] if len( d1["call_types"]) == 1 else d1["call_types"]
                        if isinstance(calls,str) : calls = [calls]
                        print("calls %s"%calls)
                        for rgen in rges :
                            param=""
                            for j,rge in enumerate(rgen) :
                                param += tpl%(prefix+calls[j],rge[0],rge[1])
                            r.append(call%param)    
                        r += ["}"]
                    else :
                        pass
                    txt += r+txtf;
                    h = Headers(os.path.join(self.bg.get_nt2_rel_tb_path(tb_name),'bench',mode),
                                name,inner=txt,guard_begin=[],guard_end=[]).txt()
                    return h.split('\n')
         
if __name__ == "__main__" :
    print __doc__
    from pprint   import PrettyPrinter
    bg = Base_gen("exponential",'pipo','simd')
    bbg = Bench_gen(bg)
    PrettyPrinter().pprint(bbg.get_gen_result())
