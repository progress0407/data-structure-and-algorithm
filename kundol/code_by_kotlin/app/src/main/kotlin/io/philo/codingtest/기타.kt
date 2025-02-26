package io.philo.codingtest

import java.util.LinkedList

/**
 * [ [1,1], [1,3], [5, 1], [5,3] ]
 */
fun main() {

    val ans = solution(arrayOf(intArrayOf(1, 1), intArrayOf(1, 3), intArrayOf(5, 1)))
    println("ans = ${ans.contentToString()}")
}

private fun solution(v: Array<IntArray>):IntArray {

    var xs = LinkedList<Int>()
    var ys = LinkedList<Int>()

    for (coord in v) {
        val (x,y) = coord
        val findX = xs.find { it == x }
        if (findX == null) {
            xs.add(x)
        } else {
            xs.removeIf { it == x }
        }
        val findY = ys.find { it == y }
        if (findY == null) {
            ys.add(y)
        } else {
            ys.removeIf { it == y }
        }
    }
    return intArrayOf(xs[0], ys[0])
}