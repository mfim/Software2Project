<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Registration Success</title>
                <center id="logo"><a href="/PowerEnjoy-war"><img src="http://localhost:8080/PowerEnjoy-war/resources/powerEnjoyLogo.png" alt="logo" style="width:700px;height:240px;"/></a></center>
        <link rel="stylesheet" href="http://localhost:8080/PowerEnjoy-war/styles/main.css" media="screen">                         
    </head>
    <body bgcolor="#006FF1">
        <yellow>Registration</yellow><white> successful!</white><br><br>
        <white>Thanks <%=request.getAttribute("username")%> for Registering to PowerEnjoy</white><br>
        <white>Check your mail for the password to LogIn</white><br><br>
        <center><a href="http://localhost:8080/PowerEnjoy-war/Login/userLoginPage.jsp">
            <input type="button" value="Login Page">
        </a></center>     
    </body>
</html>
