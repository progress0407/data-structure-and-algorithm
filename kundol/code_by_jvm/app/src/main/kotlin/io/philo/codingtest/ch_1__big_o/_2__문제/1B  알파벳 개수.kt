package io.philo.codingtest.ch_1__big_o._2__문제

fun main(args: Array<String>)  {

    val input = readln().map { it.toString() }.toList()
    val cntArr = Array<Int>(26) { 0 }

    for (alphabet in input) {
        val index = alphabet.toNum()
        cntArr[index] ++
    }

    val result = cntArr.joinToString(separator = " ")

    println(result)
}

private fun String.toNum(): Int {
    return this[0].code - 'a'.code
}
