CREATE TABLE Cliente (
    id_cliente INT PRIMARY KEY not null,
    nome VARCHAR(255) not null,
    data_nascimento DATE not null,
    cpf VARCHAR(14) unique check (cpf LIKE '___.___.___-__') not null
);

CREATE TABLE Emails (

    id_cliente int foreign key references Cliente(id_cliente) not null,
    email VARCHAR(255) not null
);

CREATE TABLE Telefone (
    id_cliente int foreign key references Cliente(id_cliente) not null,
    telefone VARCHAR(11) not null
);

CREATE TABLE Filmes (
    id_filme int PRIMARY KEY not null,
    titulo VARCHAR(255) not null,
    duracao double not null check (duracao > 0),
    classificacao int not null check (classificacao >= 18),
    estreia DATE not null
);

CREATE TABLE Generos (
    id_filme int foreign key references Filmes(id_filme) not null,
    genero VARCHAR(255) not null
);

CREATE TABLE Salas (
    numero int PRIMARY KEY not null,
    capacidade int not null check (capacidade > 0) ,
    tipo VARCHAR(255) not null default '2D',
    tecnologia VARCHAR(255) not null
);

CREATE TABLE Assentos (
    id_assento int PRIMARY KEY not null,
    numero int foreign key references Salas(numero) not null,
    fila VARCHAR(3) not null,
    numero_assento int not null,
    estado VARCHAR(50) not null,
    codigo VARCHAR(15) unique not null
);

CREATE TABLE Sessoes (
    id_sessao int PRIMARY KEY not null,
    id_filme int foreign key references Filmes(id_filme) not null,
    numero_sala int foreign key references Salas(numero) not null,
    dataa DATE not null,
    preco double not null check (preco > 0)
);

CREATE TABLE ingressos (
    id_ingresso int PRIMARY KEY not null,
    id_sessao int foreign key references Sessoes(id_sessao) not null,
    id_assento int foreign key references Assentos(id_assento) not null,
    id_cliente int foreign key references Cliente(id_cliente) not null
);

CREATE TABLE Promocoes (
    id_promocao int PRIMARY KEY not null,
    tipo VARCHAR(255) not null,
    validade DATE not null,
    valor double not null check (valor > 0)
);

CREATE TABLE CartaoFidelidade (
    id_cliente int foreign key references Cliente(id_cliente) PRIMARY KEY not null,
    pontos int not null default 1
);