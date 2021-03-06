--- src/dialog_kara_timing_copy.cpp.orig
+++ src/dialog_kara_timing_copy.cpp
@@ -69,6 +69,13 @@
 #define TEXT_LABEL_SOURCE _("Source: ")
 #define TEXT_LABEL_DEST _("Dest: ")
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 class KaraokeLineMatchDisplay : public wxControl {
 	typedef AssKaraoke::Syllable MatchSyllable;
 
@@ -358,7 +365,7 @@
 		int duration = 0;
 		for (auto const& syl : match.src)
 			duration += syl.duration;
-		res += "{\\k" + std::to_string(duration / 10) + "}" + match.dst;
+		res += "{\\k" + TO_STRING(duration / 10) + "}" + match.dst;
 	}
 
 	return res;
