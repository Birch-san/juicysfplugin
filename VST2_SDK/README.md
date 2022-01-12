Docker-based builds of juicysfplugin will `COPY` this directory into the container.  
If the VST2 headers are present in this directory: they will be used to build a VST2 plugin.  
By default this directory is empty, but if you have a VST2 SDK on your computer you can copy its contents into here prior to running a Docker build.