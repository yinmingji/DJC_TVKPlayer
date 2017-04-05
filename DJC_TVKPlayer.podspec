#
#  Be sure to run `pod spec lint DJC_TVKPlayer.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|


  s.name         = "DJC_TVKPlayer"
  s.version      = "1.0.0"
  s.summary      = "A short description of DJC_TVKPlayer."


  s.description  = <<-DESC
                   It is a test on iOS, which implement by Objective-C.
                   DESC

  s.homepage     = "https://github.com/yinmingji/DJC_TVKPlayer"
  s.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"


  s.license      = { :type => "MIT", :file => "FILE_LICENSE" }


  s.author             = { "yinmingji" => "1046759474@qq.com" }


  s.platform     = :ios

  s.ios.deployment_target = "8.0"


  s.source       = { :git => "https://github.com/yinmingji/DJC_TVKPlayer.git", :tag => "#{s.version}" }


  s.source_files = "TVKPlayer/*"

  s.public_header_files = "TVKPlayer/TVKPlayer.framework/Headers/*.h"

  s.resources = "TVKPlayer/Resources/*.bundle"

  # s.frameworks = "SomeFramework", "AnotherFramework"

  s.requires_arc = true

end
