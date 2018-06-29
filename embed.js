(function() {
    if (window.ksRunnerInit) return;

    // This line gets patched up by the cloud
    var pxtConfig = {
    "relprefix": "/pxt-microbit/",
    "workerjs": "/pxt-microbit/worker.js",
    "tdworkerjs": "/pxt-microbit/tdworker.js",
    "monacoworkerjs": "/pxt-microbit/monacoworker.js",
    "pxtVersion": "0.19.10",
    "pxtRelId": "",
    "pxtCdnUrl": "/pxt-microbit/",
    "commitCdnUrl": "/pxt-microbit/",
    "blobCdnUrl": "/pxt-microbit/",
    "cdnUrl": "/pxt-microbit/",
    "targetVersion": "0.0.0",
    "targetRelId": "",
    "targetUrl": "",
    "simUrl": "/pxt-microbit/simulator.html",
    "partsUrl": "/pxt-microbit/siminstructions.html",
    "runUrl": "/pxt-microbit/run.html",
    "docsUrl": "/pxt-microbit/docs.html",
    "isStatic": true
};

    var scripts = [
        "/pxt-microbit/highlight.js/highlight.pack.js",
        "/pxt-microbit/bluebird.min.js",
        "/pxt-microbit/typescript.js",
        "/pxt-microbit/semantic.js",
        "/pxt-microbit/marked/marked.min.js",
        "/pxt-microbit/lzma/lzma_worker-min.js",
        "/pxt-microbit/blockly/blockly_compressed.js",
        "/pxt-microbit/blockly/blocks_compressed.js",
        "/pxt-microbit/blockly/msg/js/en.js",
        "/pxt-microbit/pxtlib.js",
        "/pxt-microbit/pxtcompiler.js",
        "/pxt-microbit/pxtblocks.js",
        "/pxt-microbit/pxteditor.js",
        "/pxt-microbit/pxtsim.js",
        "/pxt-microbit/target.js",
        "/pxt-microbit/pxtrunner.js"
    ]

    if (typeof jQuery == "undefined")
        scripts.unshift("/pxt-microbit/jquery.js")

    var pxtCallbacks = []

    window.ksRunnerReady = function(f) {
        if (pxtCallbacks == null) f()
        else pxtCallbacks.push(f)
    }

    window.ksRunnerWhenLoaded = function() {
        pxt.docs.requireHighlightJs = function() { return hljs; }
        pxt.setupWebConfig(pxtConfig || window.pxtWebConfig)
        pxt.runner.initCallbacks = pxtCallbacks
        pxtCallbacks.push(function() {
            pxtCallbacks = null
        })
        pxt.runner.init();
    }

    scripts.forEach(function(src) {
        var script = document.createElement('script');
        script.src = src;
        script.async = false;
        document.head.appendChild(script);
    })

} ())
