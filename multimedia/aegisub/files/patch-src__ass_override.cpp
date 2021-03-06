--- src/ass_override.cpp.orig
+++ src/ass_override.cpp
@@ -49,6 +49,13 @@
 #include <boost/range/adaptor/transformed.hpp>
 #include <functional>
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 using namespace boost::adaptors;
 
 AssOverrideParameter::AssOverrideParameter(VariableDataType type, AssParameterClass classification)
@@ -129,11 +136,11 @@
 	if (classification == AssParameterClass::ALPHA)
 		Set(str(boost::format("&H%02X&") % mid(0, new_value, 255)));
 	else
-		Set(std::to_string(new_value));
+		Set(TO_STRING(new_value));
 }
 
 template<> void AssOverrideParameter::Set<double>(double new_value) {
-	Set(std::to_string(new_value));
+	Set(TO_STRING(new_value));
 }
 
 template<> void AssOverrideParameter::Set<bool>(bool new_value) {
