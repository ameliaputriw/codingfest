<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lupa Kata Sandi</title>
    <style>
        body {
            font-family: sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .wrapper {
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            width: 300px;
        }

        form h2 {
            text-align: center;
            margin-bottom: 20px;
        }

        .input-field {
            margin-bottom: 15px;
            position: relative;
        }

        .input-field input {
            width: 100%;
            padding: 10px;
            border: 1px solid #ddd;
            border-radius: 4px;
            outline: none;
            font-size: 16px;
        }

        .input-field label {
            position: absolute;
            left: 10px;
            top: 10px;
            color: #aaa;
            font-size: 16px;
            pointer-events: none;
            transition: all 0.2s ease;
            background-color: white;
            padding: 0 5px;
        }

        .input-field input:focus + label,
        .input-field input:valid + label {
            top: -8px;
            font-size: 12px;
            color: #333;
        }

        button {
            width: 100%;
            padding: 10px;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
            transition: background-color 0.3s ease;
            margin-top: 10px;
        }

        button:hover {
            background-color: #0056b3;
        }

        .back-to-login {
            text-align: center;
            margin-top: 15px;
            font-size: 14px;
        }

        .back-to-login a {
            color: #007bff;
            text-decoration: none; /* Pastikan dekorasi teks tidak mengganggu */
        }

        .back-to-login a:hover {
            text-decoration: underline; /* Efek hover untuk menunjukkan interaktivitas */
        }
    </style>
</head>
<body>

    <div class="wrapper">
        <form action="#">
            <h2>Lupa Kata Sandi</h2>

            <div class="input-field">
                <input type="email" required>
                <label>Masukkan email Anda</label>
            </div>

            <button type="submit">Kirim</button>

            <div class="back-to-login">
                <p>Kembali ke <a href="login.php">Login</a></p>
            </div>
        </form>
    </div>

</body>
</html>
