package io.philo.codingtest.utils

fun main() {
    val set = sortedSetOf(compareBy<Pair<Int, Int>> {it.first}.thenBy { it.second } )

    set.add(Pair(2,5))
    set.add(Pair(1,3))
    set.add(Pair(1,2))

    println("set = $set")
}