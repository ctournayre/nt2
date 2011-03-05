[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '2',
         'rturn' : {
             'default' : 'boost::fusion::tuple<ftype,ftype>',
            },
         'simd_types' : ['real_'],
         'special' : ['trigonometric'],
         'type_defs' : ['typedef typename boost::result_of<nt2::meta::floating(T)>::type ftype;'],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 11/02/2011',
             'included' : 
                ['#include <nt2/toolbox/trigonometric/include/constants.hpp>',
                 '#include <nt2/include/functions/sinpi.hpp>',
                 '#include <nt2/include/functions/cospi.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 11/02/2011',
            },
         'ranges' : {
             'default' : [['T(-40)', 'T(40)']],
            },
         'specific_values' : {
             'default' : {
                 'nt2::One<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::Mone<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::Zero<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::One<r_t0>()'],'ulp_thresh' : '0.75',},
                },
             'real_' : {
                 '-nt2::Quarter<T>()' : {'result' : ['-nt2::Sqrt_2o_2<r_t0>()', 'nt2::Sqrt_2o_2<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::Half<T>()' : {'result' : ['nt2::One<r_t0>()', 'nt2::Zero<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::Inf<T>()' : {'result' : ['nt2::Nan<r_t0>()', 'nt2::Nan<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::Mhalf<T>()' : {'result' : ['nt2::Mone<r_t0>()', 'nt2::Zero<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::Minf<T>()' : {'result' : ['nt2::Nan<r_t0>()', 'nt2::Nan<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::Mone<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::Mone<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::Nan<T>()' : {'result' : ['nt2::Nan<r_t0>()', 'nt2::Nan<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::One<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::Mone<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::Quarter<T>()' : {'result' : ['nt2::Sqrt_2o_2<r_t0>()', 'nt2::Sqrt_2o_2<r_t0>()'],'ulp_thresh' : '0.75',},
                 'nt2::Zero<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::One<r_t0>()'],'ulp_thresh' : '0.75',},
                },
             'signed_int_' : {
                 'nt2::Mone<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::Mone<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::One<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::Mone<r_t1>()'],'ulp_thresh' : '0.75',},
                 'nt2::Zero<T>()' : {'result' : ['nt2::Zero<r_t0>()', 'nt2::One<r_t0>()'],'ulp_thresh' : '0.75',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'real_' : ['nt2::sincospi(a0)'],
                },
             'property_value' : {
                 'real_' : [['nt2::sinpi(a0)', 'nt2::cospi(a0)']],
                },
             'ulp_thresh' : {
                 'real_' : ['1.0'],
                },
            },
        },
    },
]
