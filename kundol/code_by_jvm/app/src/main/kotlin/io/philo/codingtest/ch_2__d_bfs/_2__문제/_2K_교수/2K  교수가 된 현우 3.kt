package io.philo.codingtest.ch_2__d_bfs._2__문제._2K_교수

/**
 * 강사님 풀이
 */
import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()

    for (i in 0 until n) {
        val a = scanner.nextInt()
        var ret2 = 0
        var ret5 = 0

        var j = 2
        while (j <= a) {
            ret2 += a / j
            j *= 2
        }

        j = 5
        while (j <= a) {
            ret5 += a / j
            j *= 5
        }

        println(minOf(ret2, ret5))
    }
}

/*
fun main() {
    var a = 25
    var ret5 = 0

    var j = 5
    while (j <= a) {
        ret5 += a / j
        j *= 5
    }

    println(ret5)
}
*/
