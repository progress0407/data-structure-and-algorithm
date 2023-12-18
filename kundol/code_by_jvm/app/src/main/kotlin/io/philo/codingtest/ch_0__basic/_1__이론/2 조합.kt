package io.philo.codingtest.ch_0__basic._1__이론

class _2__조합

fun main() {

//    `4 C 2`()
//    `5 C 3`()

    val items = listOf(1, 2, 3, 4, 5)
    val result = combinations(items, 3)

    println(result)
}

private fun `4 C 2`() {
    val n = 4
    for (i in 1 until n) {
        for (j in i + 1..n) {
            println("$i $j")
        }
    }
}

fun `5 C 3`() {
    val n = 5
    for(i in 1 until  n) {
        for (j in i + 1..n) {
            for (k in j + 1..n) {
                println("$i $j $k")
            }
        }
    }
}

fun <T> combinations(list: List<T>, size: Int): List<List<T>> {
    if (size == 0) return listOf(emptyList())
    if (list.isEmpty()) return emptyList()

    val head = list.first()
    val rest = list.drop(1)

    val combsWithoutHead = combinations(rest, size)
    val combsWithHead = combinations(rest, size - 1).map { listOf(head) + it }

    return combsWithHead + combsWithoutHead
}

fun <T> combinations(array: Array<T>, size: Int): List<List<T>> {
    return combinations(array.toList(), size)
}

