package apperrors

type ErrCode string

const (
	Unknown ErrCode = "U000"

	GetDataFailed ErrCode = "R001"
	QueryError ErrCode = "R002"
	ScanError ErrCode = "R003"

	SqlError ErrCode = "S001"
)