create database MotelManager
use MotelManager

--I) Tạo bảng
--a) Bảng tài khoản
create table TaiKhoan
(username nvarchar(30),
bassword varchar(30),
Ngaytao date,
vaitro nvarchar(30),
cccd varchar(30) not null primary key);

insert into TaiKhoan
values
('xuanson@gmail.com','123456a','2024/01/01', N'Chủ trọ', '00120402'),
('thilinh@gmail.com','123456b','2023/11/22', N'Chủ trọ', '00130403'),
('vandat@gmail.com','123456c','2022/07/05', N'Khách trọ', '00110401'),
('hoangcuong@gmail.com','123456d','2022/10/15', N'Khách trọ','00110402'),
('duyminh@gmail.com','123456e','2022/02/01', N'Khách trọ', '00110403'),
('mauthanh@gmail.com','123456f','2023/08/20', N'Khách trọ', '00110404'),
('vandinh@gmail.com','123456g','2024/06/11', N'Khách trọ', '00110405'),
('maihuong@gmail.com','123456h','2023/12/31', N'Khách trọ', '00110406');

select * from TaiKhoan;

--b) Bảng chủ trọ
create table Chutro
(CCCDChu varchar(30) not null primary key,
Ten nvarchar(30),
Gioitinh nvarchar(30),
Namsinh date,
Sdt varchar(30),
Quequan nvarchar(30),
Chiphiphatsinh nvarchar(100),
foreign key (CCCDChu) references TaiKhoan(cccd),);

insert into Chutro
values('00120402',N'Bùi Xuân Sơn',N'Nam','2004/07/28','0866097785',N'Nam Định',N'Sơn lại tường'),
('00130403',N'Nguyễn Thị Linh',N'Nữ','2003/06/05','0986461521',N'Thái Bình',N'Xây lại cổng');

select * from Chutro;

--c) Bảng khách trọ
create table Khachtro
(CCCDKhach varchar(30) not null primary key,
Ten nvarchar(30), 
Gioitinh nvarchar(30),
Namsinh date,
Sdt varchar(30),
Quequan nvarchar(30),
foreign key (CCCDKhach) references TaiKhoan(cccd),);

insert into Khachtro
values('00110401',N'Nguyễn Văn Đạt',N'Nam','1992/12/22','0866097711',N'Hà Nội'),
('00110402',N'Hoàng Văn Cường',N'Nam','1993/11/23','0866097712',N'Lai Châu'),
('00110403',N'Đào Duy Minh',N'Nam','2000/07/06','0866097713',N'Bắc Ninh'),
('00110404',N'Nguyễn Mậu Thành',N'Nam','1999/01/02','0866097714',N'Thanh Hoá'),
('00110405',N'Phan Văn Định',N'Nam','2002/08/07','0866097715',N'Bắc Kạn'),
('00110406',N'Lê Mai Hương',N'Nữ','2004/12/22','0866097720',N'Hà Nội');

select * from Khachtro;

--d) Bảng khu trọ
create table Khutro
(IDKhutro varchar(30) not null primary key,
Tenkhutro nvarchar(30),
Diachi nvarchar(30), 
Sophong int,
Thongbao nvarchar(100),
CCCDchu varchar(30),
foreign key (CCCDchu) references Chutro(CCCDChu));

insert into Khutro
values('KT01',N'Triều Khúc',N'165 Chiến Thắng','10',N'Nộp tiền nhà 5/1','00120402'),
('KT02',N'Thanh Xuân',N'123 Nguyễn Trãi','15',N'Nộp tiền nhà 5/1','00120402'),
('KT03',N'Thuỷ Lợi','175 Tây Sơn','20',N'Nộp tiền nhà 5/1','00130403');

select * from Khutro;

--e) Bảng phòng trọ
create table Phongtro
(IDkhutro varchar(30),
Tenphongtro nvarchar(30) not null primary key,
Motaphong nvarchar(100),
Phidichvu nvarchar(100),
Giathue float,
CCCDkhach varchar(30),
foreign key (CCCDkhach) references Khachtro(CCCDKhach),
foreign key (IDkhutro) references Khutro(IDKhutro),);

insert into Phongtro
values ('KT01', '1A-KT01', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '2500000', '00110401'),
('KT02', '1A-KT02', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '3500000', '00110402'),
('KT03', '1A-KT03', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '2000000', '00110403'),
('KT01', '2A-KT01', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '1500000', '00110404'),
('KT02', '2A-KT02', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '2000000', '00110405'),
('KT03', '2A-KT03', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '2300000', null),
('KT03', '3A-KT03', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '2400000', null),
('KT02', '3A-KT02', N'Có nóng lạnh, điều hoà', N'5k/1 kWh, 3k/m3, 50k rác', '3600000', '00110406');

select * from Phongtro;

--II) Câu hỏi truy vấn
--1. Đưa ra các tài khoản của chủ trọ
select * from TaiKhoan 
where TaiKhoan.vaitro = N'Chủ trọ';

--2) Đưa ra các tài khoản của khách thuê
select * from TaiKhoan 
where TaiKhoan.vaitro = N'Khách trọ';

--3) Đưa ra thông tin các phòng chưa có người thuê
select * from Phongtro
where Phongtro.CCCDkhach is null;

--4) Đưa ra thông tin các phòng đã có người thuê
select * from Phongtro
where Phongtro.CCCDkhach is not null;

--5) Đưa ra số khách thuê trong năm 2022
select * from Khachtro join TaiKhoan on Khachtro.CCCDKhach = TaiKhoan.cccd
where year(TaiKhoan.Ngaytao) = 2022; 

--6) Đưa ra số lượng khách thuê mỗi khu trọ
select Khutro.IDKhutro,Khutro.Tenkhutro,
count(Phongtro.CCCDkhach) as N'Số lượng khách trọ' 
from Khutro join Phongtro on Khutro.IDKhutro = Phongtro.IDkhutro
group by Khutro.IDKhutro, Khutro.Tenkhutro;

--7) Đưa khu trọ có nhiều/ít khách thuê nhất
select top 1 Khutro.IDKhutro,Khutro.Tenkhutro,
count(Phongtro.CCCDkhach) as Soluongkhach
from Khutro join Phongtro on Khutro.IDKhutro = Phongtro.IDkhutro
group by Khutro.IDKhutro, Khutro.Tenkhutro
order by Soluongkhach desc; --asc;

--8) Đưa ra những khách trọ ở hà nội
select * from Khachtro
where Khachtro.Quequan = N'Hà Nội';

--9) Đưa thông tin khách hàng và độ tuổi của khách hàng
select Khachtro.Ten, (year(getdate()) - year(Khachtro.Namsinh)) as N'Số tuổi' 
from Khachtro;

--10) Đưa thông tin những khách hàng đã trọ trên 6 tháng kèm theo cột số tháng
select Khachtro.CCCDKhach, Khachtro.Ten,
DATEDIFF(month, TaiKhoan.Ngaytao,GETDATE()) as 'Số tháng trọ'
from Khachtro join TaiKhoan on Khachtro.CCCDKhach = TaiKhoan.cccd
where DATEDIFF(month, TaiKhoan.Ngaytao,GETDATE()) >= 1;
