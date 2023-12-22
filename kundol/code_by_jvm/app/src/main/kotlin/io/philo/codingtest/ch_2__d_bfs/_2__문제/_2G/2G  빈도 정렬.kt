package io.philo.codingtest.ch_2__d_bfs._2__문제._2G

/**
 * 정렬 순서
 * - 많은 것
 * - 처음 나온 값이 보다 먼저 인 것
 */
fun main() {

    val (n, c) = readln().split(" ").map { it.toInt() }
    val numList = readln().split(" ").map { it.toInt() }
    val numGroups = mutableListOf<NumGroup>()

    numList.forEachIndexed { index, num ->
        val exist = numGroups.any { it.num == num }
        if (exist) {
            val found = numGroups.find { it.num == num } ?: throw RuntimeException()
            found.cnt++
        } else {
            numGroups.add(NumGroup(num = num, firstPos = index))
        }
    }

    val sorted = numGroups.sortedWith(compareBy({ it.cnt }, { it.firstPos }))

    println("numGroups = ${numGroups}")
    println("numList = ${numList}")

}

private data class NumGroup(public val num: Int, var cnt: Int = 0, val firstPos: Int) {
}

private data class Foo(val a: Int, var b: Int) {
}