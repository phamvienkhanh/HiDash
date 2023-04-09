import QtQuick
import QtTest

import LazyTools

TestCase {
    name: "TestTools"

    function initTestCase() {
        console.log("init")
    }

    function cleanupTestCase() {
    }

    function test_case1() {
        LazyTools.callback(function () {
            console.log("hahaha")
        })
    }
}
