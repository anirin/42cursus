package apperrors

import (
	"net/http"
	"errors"
	"log"

	"github.com/labstack/echo/v4"
)

func ErrorHandler(c echo.Context, err error){
	var appError *AppError
	if !errors.As(err, &appError) {
		appError = &AppError{
			ErrCode: Unknown,
			Message: "unknown error",
			Err: err,
		}
	}
	httpStatus := http.StatusBadRequest
	switch appError.ErrCode {
	case GetDataFailed:
		log.Printf("GetDataFailed: %v", appError.Err)
		httpStatus = http.StatusInternalServerError
	case QueryError:
		log.Printf("QueryError: %v", appError.Err)
		httpStatus = http.StatusInternalServerError
	case ScanError:
		log.Printf("ScanError: %v", appError.Err)
		httpStatus = http.StatusInternalServerError
	case SqlError:
		log.Printf("SqlError: %v", appError.Err)
		httpStatus = http.StatusInternalServerError
	default:
		log.Printf("Unknown: %v", appError.Err)
		httpStatus = http.StatusInternalServerError
	}

	c.JSON(httpStatus, appError)
}