package io.philo.codingtest.ch_2__D_BFS._2__문제._2L_NBA농구

fun main() {
    val n = readln().toInt()

    val pairs = mutableListOf<Pair<Int, Pair<Int, Int>>>()
    pairs.add(Pair(0, Pair(0, 0)))

    repeat(n) {
        val str = readln().split(" ")
        val teamNo = str[0].toInt()
        val (min, sec) = str[1].split(":").map { it.toInt() }
        val totSec = min * 60 + sec

        val pointDiff = pairs.last().second

        var newPointDiff: Pair<Int, Int>
        if (teamNo == 1) {
            newPointDiff = Pair(pointDiff.first + 1, pointDiff.second)
        } else {
            newPointDiff = Pair(pointDiff.first, pointDiff.second + 1)
        }
        pairs.add(Pair(totSec, newPointDiff))
    }

    pairs.add(Pair(48 * 60, Pair(-1, -1)))

//    println("pairs = ${pairs}")

    var t1TotSec = 0
    var t2TotSec = 0
    for (i in pairs.indices) {

        if (i == 0 || i == pairs.size - 1) continue

        val (totSec, pointDiff) = pairs[i]
        val nextTotSec = pairs[i + 1].first

        val (t1, t2) = pointDiff

        if (t1 == t2) {
            // nothing
        } else if (t1 > t2) {
            t1TotSec += nextTotSec - totSec
        } else {
            t2TotSec += nextTotSec - totSec
        }
    }

//    println("t1 tot sec = ${t1TotSec}, t2 tot sec = ${t2TotSec}")
    val t1Res = "${formatter(t1TotSec / 60)}:${formatter(t1TotSec % 60)}"
    val t2Res = "${formatter(t2TotSec / 60)}:${formatter(t2TotSec % 60)}"

    println(t1Res)
    println(t2Res)
}

private fun formatter(int: Int): String {

    return if (int in 0..9)
        "0$int"
    else
        int.toString()
}