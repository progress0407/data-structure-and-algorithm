package io.philo.codingtest.ch_1__big_o._2__문제

import java.util.*

/**
 * 교안 -> Kotlin 번역
 */
fun main() {
    val scanner = Scanner(System.`in`)
    val a = IntArray(9) { scanner.nextInt() }
    a.sort()

    for (permutation in a.permutations()) {
        if (permutation.take(7).sum() == 100) {
            permutation.take(7).forEach { println(it) }
            break
        }
    }
}

fun IntArray.permutations(): Sequence<IntArray> = sequence {
    val array = this@permutations.copyOf()
    yield(array.copyOf())
    while (array.nextPermutation()) {
        yield(array.copyOf())
    }
}

fun IntArray.nextPermutation(): Boolean {
    val i = (this.size - 2 downTo 0).find { this[it] < this[it + 1] } ?: return false
    val j = (this.size - 1 downTo i + 1).first { this[i] < this[it] }
    this.swap(i, j)
    this.reverse(i + 1, this.size)
    return true
}

fun IntArray.swap(index1: Int, index2: Int) {
    val tmp = this[index1]
    this[index1] = this[index2]
    this[index2] = tmp
}

fun IntArray.reverse(fromIndex: Int, toIndex: Int) {
    var i = fromIndex
    var j = toIndex - 1
    while (i < j) {
        this.swap(i, j)
        i++
        j--
    }
}

