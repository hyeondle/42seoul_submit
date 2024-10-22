# Generated by Django 5.0.1 on 2024-02-28 21:14

import django.db.models.deletion
import django.db.models.expressions
from django.conf import settings
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='Tournament',
            fields=[
                ('id', models.BigAutoField(primary_key=True, serialize=False)),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
                ('users', models.ManyToManyField(related_name='tournaments', to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='MatchHistory',
            fields=[
                ('id', models.BigAutoField(primary_key=True, serialize=False)),
                ('level', models.PositiveIntegerField(default=0)),
                ('winner_score', models.PositiveIntegerField(default=0)),
                ('loser_score', models.PositiveIntegerField(default=0)),
                ('is_walkover', models.BooleanField(default=False)),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
                ('lose_user', models.ForeignKey(null=True, on_delete=django.db.models.deletion.PROTECT, related_name='lose_match_histories', to=settings.AUTH_USER_MODEL)),
                ('win_user', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='win_match_histories', to=settings.AUTH_USER_MODEL)),
                ('tournament', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, related_name='matche_histories', to='game.tournament')),
            ],
        ),
        migrations.CreateModel(
            name='UserMatchRecord',
            fields=[
                ('id', models.BigAutoField(primary_key=True, serialize=False)),
                ('win_count', models.PositiveIntegerField(default=0)),
                ('lose_count', models.PositiveIntegerField(default=0)),
                ('match_count', models.GeneratedField(db_persist=True, expression=django.db.models.expressions.CombinedExpression(models.F('win_count'), '+', models.F('lose_count')), output_field=models.PositiveIntegerField(default=0))),
                ('win_rate', models.GeneratedField(db_persist=True, expression=models.Case(models.When(lose_count=0, then=models.Value(0.0, output_field=models.DecimalField(decimal_places=3, default=0.0, max_digits=6)), win_count=0), models.When(then=models.Value(0.0, output_field=models.DecimalField(decimal_places=3, default=0.0, max_digits=6)), win_count=0), models.When(lose_count=0, then=models.Value(100.0, output_field=models.DecimalField(decimal_places=3, default=0.0, max_digits=6))), default=django.db.models.expressions.CombinedExpression(django.db.models.expressions.CombinedExpression(models.F('win_count'), '*', models.Value(100)), '/', django.db.models.expressions.CombinedExpression(models.F('win_count'), '+', models.F('lose_count'))), output_field=models.DecimalField(decimal_places=3, default=0.0, max_digits=6)), output_field=models.DecimalField(decimal_places=3, default=0.0, max_digits=6))),
                ('created_at', models.DateTimeField(auto_now_add=True)),
                ('updated_at', models.DateTimeField(auto_now=True)),
                ('user', models.OneToOneField(on_delete=django.db.models.deletion.PROTECT, related_name='match_records', to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]
