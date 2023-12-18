package io.philo.codingtest.ch_0__basic

class _1__순열

fun main() {
    val numbers = listOf(1, 2, 3)
    val permutations = permute(numbers)

//    println(permutations)

    for(nums in permutations) {
        for(num in nums) print("$num ")
        println()
    }
}

fun <T> permute(list: List<T>, start: Int = 0): List<List<T>> {
    if (start == list.size - 1) return listOf(list)

    val permutations = mutableListOf<List<T>>()
    for (i in start until list.size) {
        val swapped = list.toMutableList().apply {
            val temp = this[start]
            this[start] = this[i]
            this[i] = temp
        }
        permutations += permute(swapped, start + 1)
    }
    return permutations
}