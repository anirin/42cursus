# users

## Description

<details>
<summary><strong>Table Definition</strong></summary>

```sql
CREATE TABLE `users` (
  `id` int unsigned NOT NULL AUTO_INCREMENT,
  `uuid` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `is_registered` tinyint DEFAULT NULL,
  `email` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `facebook_identifier` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `twitter_identifier` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `line_identifier` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `gender` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `birthday` date DEFAULT NULL,
  `remember_token` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `avatar` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `date_last_uu_counted` date DEFAULT NULL,
  `mail_group_id` tinyint DEFAULT NULL,
  `characteristic_id` int DEFAULT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  `stripe_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin DEFAULT NULL,
  `card_brand` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `card_last_four` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `last_day_gift` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `gift_id` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `last_day_qa` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `qa_id` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `gift_content_id` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `token` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `deleted_at` timestamp NULL DEFAULT NULL,
  `sugoyose_newsletter` tinyint(1) DEFAULT NULL,
  `sugoyose_deteted_at` datetime DEFAULT NULL,
  `email_verified_at` timestamp NULL DEFAULT NULL,
  `user_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `nickname` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `last_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `furigana_last_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `furigana_first_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `privacy_policy_agree` tinyint(1) NOT NULL DEFAULT '0',
  `virth_deleted_at` datetime DEFAULT NULL,
  `meechoo` tinyint NOT NULL DEFAULT '0',
  `sugoyose` tinyint NOT NULL DEFAULT '0',
  `virth` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=[Redacted by tbls] DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
```

</details>

## Columns

| Name | Type | Default | Nullable | Extra Definition | Children | Parents | Comment |
| ---- | ---- | ------- | -------- | ---------------- | -------- | ------- | ------- |
| id | int unsigned |  | false | auto_increment |  |  |  |
| uuid | varchar(255) |  | true |  |  |  |  |
| name | varchar(100) |  | true |  |  |  |  |
| is_registered | tinyint |  | true |  |  |  |  |
| email | varchar(255) |  | true |  |  |  |  |
| password | varchar(255) |  | true |  |  |  |  |
| facebook_identifier | varchar(255) |  | true |  |  |  |  |
| twitter_identifier | varchar(255) |  | true |  |  |  |  |
| line_identifier | varchar(255) |  | true |  |  |  |  |
| gender | varchar(20) |  | true |  |  |  |  |
| birthday | date |  | true |  |  |  |  |
| remember_token | varchar(255) |  | true |  |  |  |  |
| avatar | varchar(255) |  | true |  |  |  |  |
| date_last_uu_counted | date |  | true |  |  |  |  |
| mail_group_id | tinyint |  | true |  |  |  |  |
| characteristic_id | int |  | true |  |  |  |  |
| created_at | timestamp | CURRENT_TIMESTAMP | false | DEFAULT_GENERATED |  |  |  |
| updated_at | timestamp |  | true |  |  |  |  |
| stripe_id | varchar(255) |  | true |  |  |  |  |
| card_brand | varchar(255) |  | true |  |  |  |  |
| card_last_four | varchar(4) |  | true |  |  |  |  |
| last_day_gift | text |  | true |  |  |  |  |
| gift_id | text |  | true |  |  |  |  |
| last_day_qa | text |  | true |  |  |  |  |
| qa_id | text |  | true |  |  |  |  |
| gift_content_id | text |  | true |  |  |  |  |
| token | text |  | true |  |  |  |  |
| deleted_at | timestamp |  | true |  |  |  |  |
| sugoyose_newsletter | tinyint(1) |  | true |  |  |  |  |
| sugoyose_deteted_at | datetime |  | true |  |  |  |  |
| email_verified_at | timestamp |  | true |  |  |  |  |
| user_id | varchar(255) |  | true |  |  |  |  |
| nickname | varchar(255) |  | true |  |  |  |  |
| last_name | varchar(255) |  | true |  |  |  |  |
| furigana_last_name | varchar(255) |  | true |  |  |  |  |
| furigana_first_name | varchar(255) |  | true |  |  |  |  |
| privacy_policy_agree | tinyint(1) | 0 | false |  |  |  |  |
| virth_deleted_at | datetime |  | true |  |  |  |  |
| meechoo | tinyint | 0 | false |  |  |  |  |
| sugoyose | tinyint | 0 | false |  |  |  |  |
| virth | tinyint | 0 | false |  |  |  |  |

## Constraints

| Name | Type | Definition |
| ---- | ---- | ---------- |
| PRIMARY | PRIMARY KEY | PRIMARY KEY (id) |

## Indexes

| Name | Definition |
| ---- | ---------- |
| PRIMARY | PRIMARY KEY (id) USING BTREE |

## Relations

![er](users.svg)

---

> Generated by [tbls](https://github.com/k1LoW/tbls)
