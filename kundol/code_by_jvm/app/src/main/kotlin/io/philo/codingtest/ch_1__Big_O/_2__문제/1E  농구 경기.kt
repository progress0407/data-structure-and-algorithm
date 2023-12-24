package io.philo.codingtest.ch_1__Big_O._2__문제

fun main() {

    val n = readln().toInt()

    val map = mutableMapOf<Char, Int>()

    repeat(n) {
        val firstAlphabet = readln()[0]
        val beforeVal = map[firstAlphabet]?:0
        map[firstAlphabet] = (beforeVal + 1)
    }

    val chars = mutableListOf<Char>()
    for (entry in map.entries) {
        if (entry.value >= 5) {
            chars.add(entry.key)
        }
    }
    if (chars.isNullOrEmpty()) {
        println("PREDAJA")
    } else {
        val message = chars.sorted().joinToString(separator = "")
        println(message)
    }
}