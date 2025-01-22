package apperrors

type AppError struct {
	ErrCode
	Message string
	Err error
}

func (AppError *AppError) Error() string {
	return AppError.Message
}

func (AppError *AppError) Unwrap() error {
	return AppError.Err
}

func (code ErrCode) Wrap(err error, message string) error {
	return &AppError{ErrCode: code, Message: message, Err: err}
}