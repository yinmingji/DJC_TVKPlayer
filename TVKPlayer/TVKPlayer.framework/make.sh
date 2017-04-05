lipo -create ./build/Debug-iphoneos/libtvideodownloadproxy.a ./build/Debug-iphonesimulator/libtvideodownloadproxy.a -output ./build/libtvideodownloadproxy.a
lipo -info ./build/libtvideodownloadproxy.a
lipo -create ./build/Release-iphoneos/libtvideodownloadproxy.a ./build/Release-iphonesimulator/libtvideodownloadproxy.a -output ./build/libtvideodownloadproxy_release.a
lipo -info ./build/libtvideodownloadproxy_release.a

