GdbCrashHandler
===============

A [CrashRpt](http://crashrpt.sourceforge.net/) inspired CrashHandler for Qt
based applications which attaches gdb to the dying process, collects a
stacktrace and submits it to a web service.

It works by spawing a `QProcess` in the signal handler, re-starting the
application with arguments `--crashhandle <pid>`, at which point
`GdbCrashHandler` takes over.

Usage:
------

Initialize the crash handler just after the `QApplication` instance has been created:

    GdbCrashHandler::Configuration config;
    config.applicationName = "CrashExample";
    config.applicationVersion = "1.0";
    config.applicationIcon = ":/icons/bug.png";
    config.submitMethod = GdbCrashHandler::Configuration::SubmitService;
    config.submitAddress = "http://127.0.0.1/report.php";
    GdbCrashHandler::init(argc, argv, config, /*optional*/ fileSaveCallback);

See `example/example.cpp`.

Submit service:
---------------

`GdbCrashHandler` submits the reports to a web service, using the same format as
[CrashRpt](http://crashrpt.sourceforge.net/docs/html/sending_error_reports.html),
see `service/report.php`.
