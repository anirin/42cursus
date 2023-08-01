# daily_stats

## Description

<details>
<summary><strong>Table Definition</strong></summary>

```sql
CREATE TABLE `daily_stats` (
  `id` int unsigned NOT NULL AUTO_INCREMENT,
  `stats_date` date NOT NULL,
  `uu` bigint NOT NULL DEFAULT '0',
  `pv` bigint NOT NULL DEFAULT '0',
  `inquiry` bigint NOT NULL DEFAULT '0',
  `registered_user` bigint NOT NULL DEFAULT '0',
  `accum_users` bigint NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique__stats_date` (`stats_date`)
) ENGINE=InnoDB AUTO_INCREMENT=[Redacted by tbls] DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
```

</details>

## Columns

| Name | Type | Default | Nullable | Extra Definition | Children | Parents | Comment |
| ---- | ---- | ------- | -------- | ---------------- | -------- | ------- | ------- |
| id | int unsigned |  | false | auto_increment |  |  |  |
| stats_date | date |  | false |  |  |  |  |
| uu | bigint | 0 | false |  |  |  |  |
| pv | bigint | 0 | false |  |  |  |  |
| inquiry | bigint | 0 | false |  |  |  |  |
| registered_user | bigint | 0 | false |  |  |  |  |
| accum_users | bigint | 0 | false |  |  |  |  |
| created_at | timestamp | CURRENT_TIMESTAMP | false | DEFAULT_GENERATED |  |  |  |
| updated_at | timestamp |  | true |  |  |  |  |

## Constraints

| Name | Type | Definition |
| ---- | ---- | ---------- |
| PRIMARY | PRIMARY KEY | PRIMARY KEY (id) |
| unique__stats_date | UNIQUE | UNIQUE KEY unique__stats_date (stats_date) |

## Indexes

| Name | Definition |
| ---- | ---------- |
| PRIMARY | PRIMARY KEY (id) USING BTREE |
| unique__stats_date | UNIQUE KEY unique__stats_date (stats_date) USING BTREE |

## Relations

![er](daily_stats.svg)

---

> Generated by [tbls](https://github.com/k1LoW/tbls)