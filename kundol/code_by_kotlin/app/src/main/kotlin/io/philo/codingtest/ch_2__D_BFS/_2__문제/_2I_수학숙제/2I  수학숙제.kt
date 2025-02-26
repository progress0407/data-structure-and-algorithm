package io.philo.codingtest.ch_2__D_BFS._2__문제._2I_수학숙제

fun main() {
    val n = readln().toInt()

    var numList = mutableListOf<Int>()
    repeat(n) {
        val str = readln()

        var numStr = ""

        for (i in str.indices) {
            if (str[i].isDigit()) {
                numStr += str[i]
                if (i == str.length - 1) { // 마지막일 경우
                    numList.add(numStr.toInt())
                }
            } else {
                if (numStr.isNotEmpty()) {
                    numList.add(numStr.toInt())
                }
                numStr = ""
            }
        }
    }
//    println("numList = ${numList}")

    val sortedList = numList.sortedWith(compareBy { it })

    println(sortedList)
}