{
  "targets": [
    {
      "target_name": "VidyoAddon",
      "sources": [ "VidyoAddon.cc" ],
      'conditions': [
        ['OS=="mac"', {
          "include_dirs" : [
             "<!(echo $VIDYO_CLIENT_INCL_DIR)",
          ],
          "libraries": [
            "-framework CoreLocation",
            "-framework AVFoundation",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libspeex.a",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libopus.a",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libsrtp.a",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libcrypto.a",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libssl.a",
            "<!(echo $VIDYO_CLIENT_LIB_DIR)/libVidyoClient.a",
          ]
        }],
        ['OS=="win"', {
          "include_dirs" : [
             "<!(echo %VIDYO_CLIENT_INCL_DIR%)",
          ],
          "libraries": [
            "d3d9.lib",
            "opengl32.lib",
            "glu32.lib",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\celt",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\libeay32",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\libspeex",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\opus",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\silk_common",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\silk_fixed",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\silk_float",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\srtp",
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\ssleay32",
            '-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\VidyoClient',
            "-l<!(echo %VIDYO_CLIENT_LIB_DIR%)\\vpxmt",
          ],
          'msvs_settings':
          {
            'VCLinkerTool':
            {
              'AdditionalOptions': 
              [
                '/FORCE:MULTIPLE',
              ]
            }
          }
        }],
      ],
    }
  ]
}

