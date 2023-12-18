package io.philo.codingtest.ch_0__basic

class _2__조합

fun main() {

    `4 C 2`()
    `5 C 3`()
}

private fun `4 C 2`() {
    // 4 C 2
    val n = 4
    for (i in 1 until n) {
        for (j in i + 1..n) {
            println("$i $j")
        }
    }
}

fun `5 C 3`() {
    TODO("Not yet implemented")
}
