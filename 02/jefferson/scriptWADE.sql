CREATE EXTENSION IF NOT EXISTS postgis;
--extensao espacial

CREATE TABLE colaborador (
    id_colab SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    telefone VARCHAR(20),
    email VARCHAR(100) UNIQUE,
    cidade VARCHAR(50) NOT NULL,
    uf VARCHAR(2) NOT NULL,
    latitude DECIMAL(10, 8) NOT NULL,
	longitude DECIMAL(11, 8) NOT NULL,
	posicao GEOGRAPHY(Point, 4326) NOT NULL
	-- coluna que une dois pontos para calcular uma distancia
);
CREATE INDEX index_colaborador_posicao ON colaborador USING GIST (posicao);
--indice para busca por proximidade