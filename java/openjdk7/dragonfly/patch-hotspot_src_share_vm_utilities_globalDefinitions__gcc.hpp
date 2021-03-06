--- hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp.orig	2012-08-10 16:28:55.000000000 +0000
+++ hotspot/src/share/vm/utilities/globalDefinitions_gcc.hpp
@@ -252,6 +252,9 @@ inline int g_isnan(float  f) { return is
 inline int g_isnan(double f) { return isnand(f); }
 #elif defined(__APPLE__)
 inline int g_isnan(double f) { return isnan(f); }
+#elif defined(__DragonFly__) && __DragonFly_version < 300501
+inline int g_isnan(float  f) { return __isnanf(f); }
+inline int g_isnan(double f) { return __isnand(f); }
 #elif defined(LINUX) || defined(_ALLBSD_SOURCE)
 inline int g_isnan(float  f) { return isnanf(f); }
 inline int g_isnan(double f) { return isnan(f); }
