-- 테이블 생성
CREATE TABLE t_AccountData
	(oldAccount BIGINT IDENTITY(1,1) PRIMARY KEY,
	id NVARCHAR(50) UNIQUE,
	password NVARCHAR(50) NOT NULL,
	createDate DATETIME NULL,
	logoutDate DATETIME NULL)
GO

-- 계정 데이터 넣기
CREATE PROC p_AccountData_Insert
@id NVARCHAR(50),
@password NVARCHAR(50)
AS
BEGIN
	DECLARE @count INT
	SELECT @count = COUNT(*) FROM dbo.t_AccountData WHERE id = @id
	IF @count <> 0
		RETURN 0

	INSERT INTO dbo.t_AccountData (id, password, createDate, logoutDate)
	VALUES (@id, @password, GETDATE(), NULL)

	RETURN 1
END
GO

-- 권한 주기
GRANT EXECUTE ON dbo.p_AccountData_Insert To haruu
GO

-- 더미 데이터 추가
EXEC p_AccountData_Insert 'test-01', '1234'
EXEC p_AccountData_Insert 'test-02', '1234'
GO

-- 조회 프로시저 생성
CREATE PROC p_AccountData_Select
@id NVARCHAR(50),
@password NVARCHAR(50)
AS
BEGIN
	SELECT id FROM dbo.t_AccountData
	WHERE id = @id and password = @password

	IF @@ROWCOUNT <> 0
		RETURN 0

	RETURN 1
END
GO

GRANT EXECUTE ON p_AccountData_Select To haruu
GO

EXEC p_AccountData_Select 'test-01', '1234' --success
EXEC p_AccountData_Select 'test-01', '4321' --fail
