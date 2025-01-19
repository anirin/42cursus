up: ## コンテナ起動
	cd srcs && docker compose up -d

stop: ## コンテナ停止
	cd srcs && docker stop mariadb wordpress nginx

down: ## コンテナ削除
	cd srcs && docker compose down

clean:
	cd srcs && docker compose down --rmi all --volumes --remove-orphans
	cd srcs && docker system prune -af --volumes
