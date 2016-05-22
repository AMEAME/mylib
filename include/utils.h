#pragma once

#if defined(__GNUC__)
#  if defined(__cplusplus)
#    define lamda(rettype, ARG_LIST, BODY)           \
       ([&]ARG_LIST -> rettype { BODY; } )
#  elif !defined(__clang__)
#    define lamda(rettype, ARG_LIST, BODY)           \
     ({                                               \
       rettype __lambda_funcion__ ARG_LIST { BODY; }  \
       __lambda_funcion__;                            \
     })
#  endif
#endif

#define times(n, block) { int i; \
for (i = 0; i < n; i++) block }

#define each(l, block) { int __i__; typeof(l->data[0]) e; \
for(__i__ = 0; __i__ < l->size;\
__i__++) { e = l->data[__i__]; block; } }

#define each_with_index(l, block) { int i; typeof(l->data[0]) e; \
for(i = 0; i < l->size;\
i++) { e = l->data[i]; block; } }

void* p(void* argv);
void* p_i(int argv);
