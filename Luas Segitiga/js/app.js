document.getElementById("triangleForm").addEventListener("submit", function (event) {
  event.preventDefault() // Mencegah reload halaman

  // Mendapatkan nilai input
  const base = parseFloat(document.getElementById("base").value)
  const height = parseFloat(document.getElementById("height").value)

  // Menghitung luas segitiga
  const area = 0.5 * base * height

  // Menampilkan hasil
  document.getElementById("resultText").innerText = `The area of the triangle is ${area.toFixed(2)} cm²`
})
