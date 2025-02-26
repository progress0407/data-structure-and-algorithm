package io.philo.codingtest.ch_2__D_BFS._2__문제._2G_빈도정렬

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

    val sorted = numGroups.sortedWith(compareBy({ -it.cnt }, { it.firstPos }))
    val result = sorted.flatMap { numGroup -> List(numGroup.cnt) { numGroup.num } }
    println(result.joinToString(" "))
}

private data class NumGroup(val num: Int, var cnt: Int = 1, val firstPos: Int) {
}
