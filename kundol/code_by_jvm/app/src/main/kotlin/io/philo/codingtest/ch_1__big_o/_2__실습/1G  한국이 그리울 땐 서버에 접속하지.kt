package io.philo.codingtest.ch_1__big_o._2__실습

/**
 * public Success
 *
 * private Fail
 *
 *  (StringIndexOutOfBounds)
 */
fun main() {

    val num = readln().toInt()
    val pattern = readln()
//    val asteriskIndex = pattern.indexOf("*")
    val (st, ed) = pattern.split("*")

    val resultList = mutableListOf<String>()
    repeat(num) {
        val inputStr = readln()

        val forwardStr = inputStr.substring(0, st.length)
        val backwardStr = inputStr.substring(inputStr.length - ed.length, inputStr.length)

        // ab*ab ,  ab
        if (forwardStr.length + backwardStr.length > inputStr.length) {
            resultList.add("NE")
        } else if (forwardStr == st && backwardStr == ed) {
            resultList.add("DA")
        } else {
            resultList.add("NE")
        }
    }

    resultList.forEach { println(it) }
}