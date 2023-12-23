package io.philo.codingtest.utils

fun main() {

    /**
     * 정렬 순서
     *
     * a: 오름차순
     *
     * b: 내림차순
     */
    val dataList = mutableListOf<Data>()

    // val sorted = numGroups.sortedWith(compareBy({ -it.cnt }, { it.firstPos }))

    dataList.add(Data(2, 1))
    dataList.add(Data(2, 2))
    dataList.add(Data(1, 1))
    dataList.add(Data(3, 3))

    println("dataList = ${dataList}")

    val sortedDataList = dataList.sortedWith(compareBy({ it.a }, { -it.b }))

    println("dataList = ${dataList}")
    println("sortedDataList = ${sortedDataList}")
}

private data class Data(val a: Int, val b: Int)