package io.philo.codingtest.ch_2__d_bfs._1__이론

fun main() {
    val V = 4
    val adj = Array(V) { mutableListOf<Int>() }

    adj[0].addAll(listOf(1, 2, 3))
    adj[1].addAll(listOf(0, 2))
    adj[2].addAll(listOf(0, 1))
    adj[3].add(0)

    for (i in 0 until V) {
        print("$i :: ")
        for (there in adj[i]) {
            print("$there ")
        }
        println()
    }

    // 이렇게도 할 수 있다.
/*
    for (i in 0 until V) {
        print("$i :: ")
        for (j in adj[i].indices) {
            print("${adj[i][j]} ")
        }
        println()
    }
*/
}
