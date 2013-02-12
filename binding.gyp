{
	"targets": [
		{
			"target_name": "skypekit",
			"sources": [ "skypekit.cc", "Skype.cc" ],

			"include_dirs": [
				"openssl/include",
				"skypekit/interfaces/skype/cpp_embedded/src/api",
				"skypekit/interfaces/skype/cpp_embedded/src/types",
				"skypekit/interfaces/skype/cpp_embedded/src/ipc",
				"skypekit/interfaces/skype/cpp_embedded/src/platform/threading",
				"skypekit/interfaces/skype/cpp_embedded/src/platform/threading/win",
				"skypekit/ipc/cpp",
				"skypekit/ipc/cpp/platform/se"
			],
				
			"libraries": [
				"-lws2_32.lib",
				"../skypekit/lib/Debug/skypekit-cppwrapper_2_lib.lib",
				"../skypekit/lib/Debug/skypekit-cyassl_lib.lib",
				"../skypekit/lib/Debug/skypekit-ipccpp.lib"
			]
		}
	]
}