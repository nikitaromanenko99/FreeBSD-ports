--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2023-02-11 09:11:04 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -23,7 +23,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -41,7 +41,7 @@ class ImageSkia;
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 struct LinuxFileRegistration {
   std::string xdg_command;
   std::string file_contents;
@@ -91,7 +91,7 @@ struct ShortcutOverrideForTesting
 #elif BUILDFLAG(IS_MAC)
   base::ScopedTempDir chrome_apps_folder;
   std::map<base::FilePath, bool> startup_enabled;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedTempDir desktop;
   base::ScopedTempDir startup;
   std::vector<LinuxFileRegistration> linux_file_registration;
@@ -144,7 +144,7 @@ struct ShortcutInfo {
   std::set<std::string> file_handler_extensions;
   std::set<std::string> file_handler_mime_types;
   std::set<std::string> protocol_handlers;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
