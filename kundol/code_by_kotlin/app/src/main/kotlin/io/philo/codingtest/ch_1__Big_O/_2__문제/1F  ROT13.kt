package io.philo.codingtest.ch_1__Big_O._2__문제

fun main() {

    val fn = mutableMapOf<Char, Char>()

    // make fn
    for (asciiNum in 'A'.code..'Z'.code) {
        val asciiCh = asciiNum.toChar()
        fn[asciiCh] = largeAlphabetTranslator(asciiNum)
    }
    for (asciiNum in 'a'.code..'z'.code) {
        val asciiCh = asciiNum.toChar()
        fn[asciiCh] = smallAlphabetTranslator(asciiNum)
    }


    // calc
    val input = readln()
    val res = mutableListOf<Char>()
    for (ch in input) {
        if (ch.isLetter()) {
            val element = fn[ch]!!
            res.add(element)
        } else {
            res.add(ch)
        }
    }

    println(res.joinToString(""))
}

private fun largeAlphabetTranslator(asciiNum: Int): Char {
    val startLimit = 'A'.code
    val endLimit = 'Z'.code

    if (asciiNum + 13 > endLimit) {
        val rest = 13 - (endLimit - asciiNum + 1)
        return (startLimit + rest).toChar()
    } else {
        return (asciiNum + 13).toChar()
    }
}

private fun smallAlphabetTranslator(asciiNum: Int): Char {
    val startLimit = 'a'.code
    val endLimit = 'z'.code

    if (asciiNum + 13 > endLimit) {
        return (asciiNum + 13 - 26).toChar()
    } else {
        return (asciiNum + 13).toChar()
    }
}