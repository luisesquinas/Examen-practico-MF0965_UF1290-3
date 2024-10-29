document.getElementById('registroUsuario').onsubmit = async function (e) {
    e.preventDefault();

    const usuario = document.getElementById('usuario').value;
    const orden = "crea";

    const response = await fetch(`/cgi-bin/funciones.cgi`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'u': usuario,
            'orden': orden
        })
    });
    const data = await response.text();
    document.getElementById('resultado').innerHTML = decodeURI(data);
};

// Manejo del botón de eliminación
document.getElementById('eliminarUsuarioBtn').onclick = async function () {
    const usuario = document.getElementById('usuario').value;
    const orden = "elimina";

    const response = await fetch(`/cgi-bin/funciones.cgi`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'u': usuario,
            'orden': orden
        })
    });
    const data = await response.text();
    document.getElementById('resultado').innerHTML = decodeURI(data);
};
