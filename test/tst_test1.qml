import QtQuick
import QtTest

import HiDash

TestCase {
    name: "TestTools"

    Rectangle {
        width: 100
        height: 100
        color: "red"
    }

    function initTestCase() {

    }    

    function test_delay_call () {
        let checkCallback = false
        HiDash.delay(100, function () {
            checkCallback = true
        })

        wait(150)

        verify(checkCallback, "test delay call 1")
    }

    function test_delay_cancel () {
        let checkCallback = false
        let timerId = HiDash.delay(100, function () {
            checkCallback = true
        })

        wait(50)
        HiDash.cancel(timerId)

        verify(!checkCallback, "test delay call 2")

        wait(100)

        verify(!checkCallback, "test delay call 2")
    }

    function test_debounce_call () {
        let checkCallback = false
        let debounce = HiDash.debounce(this, function () {
            checkCallback = true
        }, 1000, {leading: true, trailing: true, maxWait: 120})

        debounce.call()
        verify(checkCallback, "test leading")
        checkCallback = false;

        debounce.call()
        debounce.call()
        debounce.call()

        verify(!checkCallback, "recheck test leading")

        wait(130)
        debounce.call()
        verify(checkCallback, "test maxWait")
        checkCallback = false;

        wait(1200)
        verify(checkCallback, "test debounce")
    }

    function cleanupTestCase() {

    }
}
