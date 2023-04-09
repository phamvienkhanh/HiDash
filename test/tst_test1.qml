import QtQuick
import QtTest

import LazyTools

TestCase {
    name: "TestTools"

    function initTestCase() {
    }

    function cleanupTestCase() {
    }

    function test_delay_call() {
        let checkCallback = false
        LazyTools.delayCall(100, function () {
            checkCallback = true
        })

        wait(200)

        verify(checkCallback, "test delay call")
    }
}
