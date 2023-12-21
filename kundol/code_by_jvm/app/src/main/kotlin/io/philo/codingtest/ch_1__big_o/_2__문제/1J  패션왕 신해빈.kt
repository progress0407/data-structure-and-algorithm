package io.philo.codingtest.ch_1__big_o._2__문제

fun main() {

    val N = readln().toInt()

    repeat(N) { i ->
        val M = readln().toInt()

//        println("i = ${i}")

        val mapOfList = mutableMapOf<String, MutableList<String>>()

        loop@ for (j in 0..M - 1) {
//            println("j = ${j}")
            val (name, category) = readln().split(" ")
            if (mapOfList[category] == null) {
                mapOfList[category] = mutableListOf()
                mapOfList[category]!!.add(name)
            } else {
                mapOfList[category]!!.add(name)
            }

            if (i == N - 1 && j == M - 1) {
                break@loop
            }
        }

        val result = mapOfList.map { it.value }
            .map { it.size + 1 }
            .fold(1) { total, next -> total * next } - 1

//        println("result = ${result}")
        println(result)
    }
}
