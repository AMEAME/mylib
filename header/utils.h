#pragma once

#if defined(__GNUC__)
#  if defined(__cplusplus)
#    define LAMBDA(rettype, ARG_LIST, BODY)           \
       ([&]ARG_LIST -> rettype { BODY; } )
#  elif !defined(__clang__)
#    define LAMBDA(rettype, ARG_LIST, BODY)           \
     ({                                               \
       rettype __lambda_funcion__ ARG_LIST { BODY; }  \
       __lambda_funcion__;                            \
     })
#  endif
#endif

#define times(n, i, block) for (i = 0; i < n; i++) block
