Pod::Spec.new do |s|


  s.name         = "DJC_TVKPlayer"
  s.version      = "1.0.4"
  s.summary      = "A short test for DJC_TVKPlayer."


  s.description  = <<-DESC
                   It is a test on iOS, which implement by Objective-C.
                   DESC

  s.homepage     = "https://github.com/yinmingji/DJC_TVKPlayer"

  s.license      = { :type => "MIT", :file => "FILE_LICENSE" }


  s.author             = { "yinmingji" => "1046759474@qq.com" }


  s.platform     = :ios

  s.ios.deployment_target = "8.0"


  s.source       = { :git => "https://github.com/yinmingji/DJC_TVKPlayer.git", :tag => "#{s.version}" }

  s.vendored_frameworks = 'TVKPlayer/TVKPlayer.framework'

  s.requires_arc = true

end
