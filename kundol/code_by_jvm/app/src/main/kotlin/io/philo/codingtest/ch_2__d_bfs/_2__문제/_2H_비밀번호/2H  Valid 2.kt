package io.philo.codingtest.ch_2__d_bfs._2__문제._2H_비밀번호


private val vowels = arrayOf("a", "e", "i", "o", "u")

fun main() {

    val result = isValid2("ptoui") // false
    println("result = ${result}")
}

/**
 * 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 */
private fun isValid2(str: String): Boolean {

    var cnt = 1
    var lastCategory = 0 // 0 모음, 1 자음

    // 처음 값
    if (vowels.contains(str.first().toString())) {
        lastCategory = 0
    } else {
        lastCategory = 1
    }

    for (i in str.indices) {
        if (i == 0) continue

        val target = str[i].toString()

        // 모음
        if (vowels.contains(target)) {
            // 이전것도 모음이면
            if (lastCategory == 0) cnt++
            // 아니면 초기화
            else cnt = 1
            lastCategory = 0
        } else { // 자음
            if (lastCategory == 1) cnt++
            else cnt = 1
            lastCategory = 1
        }
        if (cnt == 3) return false
    }
    return true
}