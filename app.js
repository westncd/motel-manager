  $('#login').submit(function(e) {

    e.preventDefault();

    let username = $('#username').val(); 
    let password = $('#password').val();

    if(username == 'admin' && password == '1234') {
      window.location.href = 'home.html';
    } else {
      alert('Sai tài khoản hoặc mật khẩu');
    }

  });

  function showHostLogin() {
    document.getElementById("host-login").style.display = "block";  
    document.getElementById("tenant-login").style.display = "none";
  }

  function showTenantLogin() {
    document.getElementById("tenant-login").style.display = "block";
    document.getElementById("host-login").style.display = "none"; 
  }

  function loginHost() {
    let id = document.getElementById("host-id").value;
    window.location.href = "host.html?id=" + id; 
  }

  function loginTenant() {
    let motelId = document.getElementById("motel-id").value; 
    let roomNo = document.getElementById("room-no").value;
    window.location.href = "tenant.html?motelid=" + motelId + "&roomno=" + roomNo;
  }

