package io.philo.codingtest.ch_6__이분탐색._1__이론._1_이분탐색_암기왕

/**
 * 완전 탐색
 */
fun main() {
    val t = readln().toInt()

    repeat(t) {
        readln().toInt() // 수첩 1
        val s1 = readln().split(" ").map { it.toInt() }

        readln().toInt() // 수첩 2
        val s2 = readln().split(" ").map { it.toInt() }

        for (target in s2) {
            val exist = s1.contains(target)
            println(if(exist) 1 else 0)
        }
    }
}
