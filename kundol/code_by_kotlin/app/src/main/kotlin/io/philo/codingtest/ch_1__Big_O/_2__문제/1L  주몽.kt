package io.philo.codingtest.ch_1__Big_O._2__문제

/**
 * 메모리 초과
 */
fun main() {

    val N = readln().toInt()
    val M = readln().toInt()

    val list = readln().split(" ").map { it.toInt() }

    val combiList = combinations(list, 2)

    val result = combiList.filter { it.sum() == M }.size
    println(result)
}

private fun <T> combinations(list: List<T>, size: Int): List<List<T>> {
    if (size == 0) return listOf(emptyList())
    if (list.isEmpty()) return emptyList()

    val head = list.first()
    val rest = list.drop(1)

    val combsWithoutHead = combinations(rest, size)
    val combsWithHead = combinations(rest, size - 1).map { listOf(head) + it }

    return combsWithHead + combsWithoutHead
}

private fun <T> combinations(array: Array<T>, size: Int): List<List<T>> {
    return combinations(array.toList(), size)
}